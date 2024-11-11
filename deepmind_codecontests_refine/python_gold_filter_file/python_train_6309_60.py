nsticks, ncrossed = map(int,input().split())
# i = 0
# if ncrossed == 1:
#     if nsticks % 2 == 0:
#         print("NO")
#         quit()
#     else:
#         print("YES")
#         quit()
# while True:
#     if nsticks >= ncrossed:
#         i += 1
#         nsticks = nsticks - ncrossed
#     else:
#         break

# if i % 2 == 0: print("NO")
# else: print("YES")
a = nsticks//ncrossed
if (a % 2) == 0:
    print("NO")
else:
    print("YES")
