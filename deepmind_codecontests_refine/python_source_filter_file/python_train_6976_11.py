n = int(input())
*s1, = input().split()
s2 = s1[:]

def bubbleSort(s):
    flag = True
    while flag:
        flag = False
        for i in range(n-1):
            if int(s[i][1]) > int(s[i+1][1]):
                s[i],s[i+1] = s[i+1],s[i]
                flag = True
    return s

def selectionSort(s):
    for i in range(n):
        minj = i
        for j in range(i+1,n):
            if int(s[minj][1]) > int(s[j][1]):
                minj = j
        s[i],s[minj] = s[minj],s[i]
    return s

print(' '.join(bubbleSort(s1)))
print("Stable")
print(' '.join(selectionSort(s2)))
if s1 == s2:
    print("Stable")
else:
    print("Not Stable")

