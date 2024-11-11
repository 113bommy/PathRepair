
get = input()
if get[:int((len(get)-1)/2)] == get[int(((len(get)+3)/2)-1):]:
    print('Yes')
else:
    print('No')