def palindrome(str):
    x1 = str[::-1]
    if x1 == str:
       print('It is a palindrome')
    else:
       print('It is not a palindrome')

str = input("Enter a string: ")
palindrome(str)