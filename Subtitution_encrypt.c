
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find_index(char code[],char char_to_find){
  for(int i = 0 ; i < 26; i ++){
    if(code[i] == char_to_find){
      return i;
    }
  }
  return -1;
}

char* encrypt(char *message,char code[]){
  int length = strlen(message);
  char *encrypted_message = (char *) malloc(sizeof(char)*length);

  for(int i = 0; i < length; i++){
    int encryption_index = tolower(message[i]) - 'a';
    if(encryption_index >= 0 && encryption_index < 26){
      encrypted_message[i] = code[encryption_index];
    }else{
      encrypted_message[i] = message[i];
    }
  }
  return encrypted_message;
}

char *decrypt(char *message,char code[]){
  int length = strlen(message);
  char *decrypted_message = (char *) malloc(sizeof(char)*length);
  for(int i = 0; i <length; i++){
    int decryption_index = tolower(message[i]) + 'a';
    if(decryption_index >= 0 && decryption_index < 26){
      int code_index = find_index(code,tolower(message[i]));
      decrypted_message[i] = 'a' + code_index;
    }else{
      decrypted_message[i] = message[i];
    }
  }
  return decrypted_message;
}

int main(){
    char *message[300];
    char code[26] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};

    printf("Enter message here: ");
    scanf("%[^\n]s", &message);

  char *encrypted_message = encrypt(message,code);
  char *decrypted_message = decrypt(encrypted_message,code);
  printf("Encrypted Message: %s\n",decrypted_message);
}
