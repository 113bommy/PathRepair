from sys import stdin

t = int(stdin.readline())

def c(l,r,msg):
    f = True
    if l > 0 and not msg[l-1].isdigit() and not msg[l-1].isalpha():
        pass
    elif l == 0:
        pass
    else:
        f = False

    if r == len(msg) - 1:
        pass
    elif not msg[r+1].isdigit() and not msg[r+1].isalpha():
        pass
    else:
        f = False

    return f


def dd(i):
    if i - 1 in no_author_set:
        authors[i-1].discrad(authors[i])
        if len(authors[i-1]) == 1:
            no_author_set.discard(i-1)
            for d in authors[i-1]:
                authors[i-1] = d
                break
            dd(i-1)
        if len(authors[i-1]) == 0:
            return False
    if i + 1 in no_author_set:
        authors[i+1].discard(authors[i])
        if len(authors[i+1]) == 1:
            no_author_set.discard(i+1)
            for d in authors[i+1]:
                authors[i+1] = d
                break
            dd(i+1)
        if len(authors[i-1]) == 0:
            return False
    return True

try:
    answers = []
    for i in range(t):
        ans = True
        n = int(stdin.readline())
        names = set(stdin.readline().strip().split())
        m = int(stdin.readline())
        authors = list()
        messages = list()
        no_author = list()
        no_author_set = set()
        for j in range(m):
            line = stdin.readline().strip()
            author, msg = line.split(':')
            messages.append(msg)
            if author == '?':
                no_author.append(j)
                no_author_set.add(j)
                a_set = set()
                for name in names:
                    l = msg.find(name)
                    while l != -1:
                        if c(l,l+len(name)-1, msg):
                            a_set.add(name)
                        l = msg.find(name,l+len(name))
                authors.append(names-a_set)
                if j-1 not in no_author_set:
                    authors[j].discard(authors[j-1])
            else:
                authors.append(author)
                if j - 1 in no_author_set:
                    authors[j-1].discard(author)

        for j in no_author:
            if j in no_author_set:
                if len(authors[j]) == 1:
                    no_author_set.discard(j)
                    for d in authors[j]:
                        authors[j] = d
                        break
                    if not dd(j):
                        ans = False
                elif len(authors[j]) == 0:
                    ans = False

        no_author = list()
        for j in no_author_set:
            no_author.append(j)
        no_author.sort()
        for i in no_author:
            for d in authors[i]:
                authors[i] = d
                break
            if i + 1 in no_author_set:
                authors[i+1].discard(authors[i])
        if not ans:
            answers.append('Impossible')
        else:
            for j in range(m):
                answers.append('%s:%s'%(authors[j],messages[j]))
except Exception as e:
    print(e)

for m in answers:
    print(m)