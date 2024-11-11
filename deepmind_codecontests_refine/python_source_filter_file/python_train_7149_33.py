s = input().split(".")
print(s)
done=0
for x in s:
    if "ABC" in x or "ACB" in x or "BAC" in x or "BCA" in x or "CAB" in x or "CBA" in x:
        done=1
        print("Yes")
        break
if not done:
    print("No")
