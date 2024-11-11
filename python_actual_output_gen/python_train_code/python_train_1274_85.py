n = int (input())
answer = 0
arr = input().split()
a,b = map(int , input().split())
for i in range(0,b-1): 
    answer+=int(arr[i])
print(answer)
