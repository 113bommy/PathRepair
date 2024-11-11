hour, mi = list(map(int,input().split(':')))
h, m = list(map(int, input().split(':')))
a = (hour*60) + mi
b = (h*60) + m
c,d = list(divmod((b-a)//2, 60))

print(str(c+hour).zfill(2)+':'+str(d+mi).zfill(2))