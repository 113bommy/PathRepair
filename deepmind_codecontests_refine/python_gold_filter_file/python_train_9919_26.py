



"""
n je stevilka apartmaja, rabim nardit da dobim na katerem štuku živi...
"""

for i in range(int(input())):
    n,x = map(int, input().split())

    if(n<3):
        print(1)

    elif ((n-2)%x != 0):
        print(int((n-2)/x + 2))
    else:
        print(int((n - 2) / x + 1))