n = int(input())
a = input()
b = input()
cnt = 0
for i in range(n):
    if int(a[i])==0 and int(b[i])>5:
        cnt+=(10-int(b[i]))
    elif int(a[i])==1 and int(b[i])>6:
        cnt+=(11-int(b[i]))
    elif int(a[i])==2 and int(b[i])>7:
        cnt+=(12 - int(b[i]))
    elif int(a[i])==3 and int(b[i])>8:
        cnt+=(13 - int(b[i]))
    elif int(b[i])==0 and int(a[i])>5:
        cnt+=(10-int(a[i]))
    elif int(b[i])==1 and int(a[i])>6:
        cnt+=(11-int(a[i]))
    elif int(b[i])==2 and int(a[i])>7:
        cnt+=(12 - int(a[i]))
    elif int(b[i])==3 and int(a[i])>8:
        cnt+=(13 - int(a[i]))
    else:
        cnt +=abs(int(a[i])-int(b[i]))
print(cnt)