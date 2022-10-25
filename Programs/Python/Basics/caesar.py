# A program on Caesar Cipher

text = str(input("Enter a word: "))
s = int(input("Enter the shift: "))

result = ""

for i in range(len(text)):
  char = text[i]
  if(char.isupper()):
    result += chr((ord(char) + s-65) % 26 + 65)
  else:
    result += chr((ord(char) + s - 97) % 26 + 97)

print(f"Caesar Cipher: {result}")
