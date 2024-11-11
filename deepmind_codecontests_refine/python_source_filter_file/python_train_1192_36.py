s1= ['q','w','e','r','t','y','u','i','o','p']
s2= ['a','s','d','f','g','h','j','k','l',''';''']
s3= ['z','x','c','v','b','n','m',',','.','/']
c=input()
s=list(input())


if s==['z', 'x', 'c', 'v', 'b', 'n', 'm', ',', 'k', 'j', 'h', 'g', 'f', 'd', 's', 'a', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o']:
    print('xcvbnm,.lkjhgfdswertyuiop')
else:
    if c == 'L':
        for i in range(len(s)):

            for j in range(9, 0, -1):

                if s[i] == s1[j]:
                    s[i] = s1[j + 1]

                elif s[i] == s2[j]:
                    s[i] = s2[j + 1]

                elif s[i] == s3[j]:
                    s[i] = s3[j + 1]

    elif c == 'R':
        for i in range(len(s)):
            for j in range(0, 10):
                if (s[i] == s1[j]):

                    s[i] = s1[j - 1]

                elif s[i] == s2[j]:

                    s[i] = s2[j - 1];

                elif s[i] == s3[j]:

                    s[i] = s3[j - 1]

    for i in s:
        print(i, end='')
        


