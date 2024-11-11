a = int(input())
t = 0
for i in input().split():
    t+=100-int(i)
print(100-t/a)