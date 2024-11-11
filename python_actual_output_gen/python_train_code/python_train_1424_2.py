s = input()

terms = []
s1 = s.split(';')

for x in s1:
    terms += x.split(',')

numbers = []
rest = []

for x in terms:
    if x.isdecimal():
        if x[0] != '0' or int(x)==0:
            numbers.append(x)
        else:
            rest.append(x)
    else:
        rest.append(x)

if len(numbers):
    print(''.join(['"', ','.join(numbers), '"']))
else:
    print('-')

if len(rest):
    print(''.join(['"', ','.join(rest), '"']))
else:
    print('-')
