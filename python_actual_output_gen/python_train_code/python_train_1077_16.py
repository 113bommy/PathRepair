n=int(input())
w=list(map(int, input().split())) 
sn=sum(w)
abs_list=[abs(sn-sum(w[:i+1])) for i in range(n)]
print(min(abs_list))