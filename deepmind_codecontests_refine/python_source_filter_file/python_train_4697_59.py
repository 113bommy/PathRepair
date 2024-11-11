
# coding: utf-8

# In[5]:


sum = 0
longest = 0
#a = input()
#b = input()
#c = input()

a, b, c = map(int, input().strip().split())

if a >= b and a >= c :
    sum = b + c
    longest = a
elif b >= a and b >= c :
    sum = a + c
    longest = b
elif c >= a and c >= b :
    sum = a + b
    longest = c
    
if sum >= longest :
    print(0)
else:
    print(longest - sum + 1)


