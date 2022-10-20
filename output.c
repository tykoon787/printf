diff --git a/_printf.c b/_printf.c
index de917b6..2f2d82e 100644
--- a/_printf.c
+++ b/_printf.c
@@ -1,6 +1,4 @@
-#include <stdio.h>
 #include <stdarg.h>
-#include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include "main.h"
@@ -11,7 +9,6 @@
  *
  * Return: Number of bytes written to `stdout`
  */
-
 int _printf(const char *format, ...)
 {
 	int i = 0, j = 0, len = 0;
@@ -19,12 +16,11 @@ int _printf(const char *format, ...)
 	char *buffer, *str_arg;
 
 	va_start(args, format);
-	while (format[i] != '\0')
-	{
+	while (format[len] != '\0')
 		len++;
-		i++;
-	}
 	buffer = malloc(sizeof(char) * len);
+	if (buffer == NULL)
+		return (-1);
 	for (i = 0; i < len; i++)
 	{
 		if (format[i] == '%')
