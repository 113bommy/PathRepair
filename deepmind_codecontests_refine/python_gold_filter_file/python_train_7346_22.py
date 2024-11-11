# cook your dish here
n = int(input())
ans = int((-1 + (1+ 8*n)**(1/2))//2)
# print(ans)
ls = list(range(1, ans))
ls.append(n - ((ans*(ans-1))//2))
print(ans)
print(*ls)