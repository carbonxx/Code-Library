num = int(input('Enter the Number :'))
origi_num=num
reversed_num = 0

while num != 0:
    digit = num % 10
    reversed_num = reversed_num * 10 + digit
    num //= 10

print("Reversed Number: " + str(reversed_num))
if origi_num==reversed_num :
    print('Its a Palindrome')
else :
    print('Its not a Palindrome')