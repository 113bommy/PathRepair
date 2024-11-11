n=input()
steps=input()
steps=[i for i in steps]
if 'R' in steps:
    c=[index for index, value in enumerate(steps) if value == 'R']
    if 'L'in steps:
        print(min(c)+1,' ',max(c)+1)
    else:
        print(min(c) + 1, ' ', max(c) + 2)
else:
    c=[index for index, value in enumerate(steps) if value == 'L']
    print(max(c)+1,' ',min(c))