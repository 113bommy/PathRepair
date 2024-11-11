w=input()
c=0
while True:
    t=input().lower()
    if t=='END_OF_TEXT':
        print(c)
        break
    c+=t.lower().split().count(w)
