s = list(map(int, input().split(":")))
t = list(map(int, input().split(":")))
h1=s[0]*60+s[1]
h2=t[0]*60+t[1]
a=(h1-h2 if h1-h2>=0 else h1-h2+24*60)
print(a//60 if a//60>=10 else "0"+str(a//60), a%60 if a%60>=10 else "0"+str(a%60),sep=":")