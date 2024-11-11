n = int(input())
displayed = {}
top = None
for i in range(n):
    chat = input()
    try:
        a = displayed[chat]
        previous = a[0]
        nextone = a[1]
        if previous:
            displayed[previous][1] = nextone
            if nextone: displayed[nextone][0]=previous
            displayed[chat] = [None, top]
            if top:
                displayed[top][0] = chat
            top = chat
    except KeyError:
        displayed[chat] = [None, top]
        if top:
            displayed[top][0] = chat
        top = chat
    #print(displayed)
    #print(top)
li = []
while top:
    #print(top)
    li.append(top)
    top = displayed.pop(top)[1]
    #print(displayed)

print('\n'.join(li))