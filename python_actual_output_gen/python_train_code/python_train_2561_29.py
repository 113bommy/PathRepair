n = int(input())
for i in range(n):
    str = input()
    j = 0
    k = ""
    while(j<len(str)):
        k += str[j]
        j+=2
        k += str[-1]
        print(k)