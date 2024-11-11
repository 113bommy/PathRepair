n=input()
print':'.join(map(str,[n/3600,n%3600/60,n%60]))