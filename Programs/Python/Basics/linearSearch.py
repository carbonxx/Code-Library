# functions on linear search

def search(arr, x):
  for i in range(len(arr)):
    if arr[i] == x:
      return i
  return -1
    
    
arr = [1,12,15,27,32,54,99,108,120,157,176]
x = int(input("Enter the number you want to search: "))

if search(arr,x) != -1:
  print(f"The number is present in {search(arr,x)} position.")
else:
  print("The number doesn't exist in the mentioned array.")
