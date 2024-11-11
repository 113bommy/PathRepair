n=int(input())
s=[input() for i in range(n)]
m=int(input())
t=[input() for i in range(n)]

print(max(0,max(s.count(i)-t.count(i) for i in set(s))))
    


