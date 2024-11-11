W=input().lower()
cnt=0
while True:
    T=input()
    if T=='END_OF_TEXT': break
    cnt += T.lower().count(W)
print(cnt)