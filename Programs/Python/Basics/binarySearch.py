# functions on binary search

def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1
 
arr = [1,12,15,27,32,54,99,108,120,157,176]
x = int(input("Enter the number you want to search: "))
 
if binary_search(arr, x) != -1:
    print(f"The number is present in {str(binary_search(arr, x))} position")
else:
    print("The number doesn't exist in the mentioned array.")
