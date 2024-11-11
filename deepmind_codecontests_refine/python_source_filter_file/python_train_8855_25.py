import sys
w=input().upper()
c=0
for s in sys.stdin:
    if "END_OF_TEXT" in s:
        break
    c += str(s).upper().count(w)
print(c)