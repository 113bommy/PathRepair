n = int(input())
mas = list(map(int,input().split(" ")))
ma=0
mi = 999999999999
for i in range(1,n-1):
    ma=max(ma, abs(mas[i]-mas[i-1]),abs(mas[i]-mas[i-1]))
    mi = min(mi,abs(mas[i+1]-mas[i-1]))
print(max(mi,ma))