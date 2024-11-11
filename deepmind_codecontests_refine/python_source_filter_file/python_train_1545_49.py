s=[input()for _ in range(int(input()))]
t=[input()for _ in range(int(input()))]
a=set(s)
print(max(0,max(s.count(a[i])-t.count(a[i]) for i in range(len(a)))))