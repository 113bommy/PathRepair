'''
name = input()
name = set(name)
if len(name)%2 == 0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')
'''
def check(x):
    x = set(str(x))
    if len(x) == 4:
        return True
    else:
        return False
year = int(input())
while not check(year):
    year += 1
print(year)
