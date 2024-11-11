s = input()

stack = [s[0]]

for sign in s:
    if len(stack) != 0 and sign == stack[-1]:
        stack.pop()
    else:
        stack.append(sign)
        
if len(stack) == 0:
    print ("Yes")
else:
    print ("No")