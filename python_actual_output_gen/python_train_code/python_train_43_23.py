n = int(input())
string = input()
flag = 0
for i in range(0,n-1):
    if string[i] > string[i+1]:
        flag = 1
        print("YES")
        print(i,i+1)
        break
if flag == 0:
    print("NO")
