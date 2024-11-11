def answer(handles):
    for handle in handles:
        if handle.before >= 2400:
            if handle.after > handle.before:
                print("YES")
                return 1
    print("NO")
    return 0

class handle():
    def __init__(self, name, before, after):
        self.name = name
        self.before = before
        self.after = after

n = int(input())
handles = []
for i in range(0, n):
    string = input().split()
    name = string[0]
    before = int(string[1])
    after = int(string[2])
    handles.append(handle(name, before, after))
answer(handles)