n, t, k, d = input().split()
total = (int(t)/int(k))*int(n)
o = (int(k)/int(t))*int(d)
if int(k) > int(n):
    print("NO")
elif int(d) < int(t) and int(k) < int(n):
    print("YES")
elif int(d) >= int(t):
    if int(n) - int(o) > int(k):
        print("YES")
    else:
        print("NO")





