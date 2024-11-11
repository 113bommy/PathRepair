'''
https://codeforces.com/problemset/problem/754/A
'''

def allZeroes(arr):
    for i in arr:
        if i != 0: return False
    
    return True

def sumArray(arr):
    summ = 0
    for i in arr: summ+= i

    return summ

def solve(arr):
    if allZeroes(arr):
        print("No")
        return
    
    if sumArray(arr) != 0:
        print("Yes")
        print(1)
        print(1, len(arr))
        return
    
    summ = 0

    for i in range(len(arr)):
        summ+= arr[i]

        if summ != 0:
            print("Yes")
            print(2)
            print(1, i+1)
            print(i+2, len(arr))
            return


n  = input()

arr = list(map(int, input().split()))

solve(arr)

    


