#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Repeat the char the number of time provided.
/// @details Similar to javascript of python String.repeat(count) function
/// @param ch The character to be repeated
/// @param count The number of times we will repeat the the {ch}
/// @return string representation of the repeated char
char *repeat_char(char ch, int count)
{
  char *result = malloc(count + 1); // +1 for the null terminator
  if (result == NULL)
  {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }

  // Use the memset function to repeat the character
  memset(result, ch, count);

  result[count] = '\0'; // Null-terminate the string
  return result;
}
