n,m = map(int,input().split())
a = input()
b = input()
t = a[0]+b[0]+a[-1]+b[-1]
if t=='<v>^' or t=='>v<^':
    print("YES")
else:
    print("NO")
