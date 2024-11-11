tam = int(input())
number = input()
num = [int(i) for i in number]
fun = [int(x) for x in input().split()]

ini = 0 

for w in range(tam): 
    if fun[num[w]-1] > num[w]:
        ini = w
        break

for j in range(ini,tam):
    if fun[num[j]-1] > num[j]:
        num[j] = fun[num[j]-1]
    else:
        break
num = [str(i) for i in num]
ans = "".join(num)
print(ans)