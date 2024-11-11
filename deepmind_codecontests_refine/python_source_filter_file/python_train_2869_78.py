# A. Way Too Long Words
# time limit per test1 second
# memory limit per test256 megabytes
# inputstandard input
# outputstandard output

def main():
    n = int(input())
    words = []
    for _ in range(n):
        w = input()
        words.append(w)
    for word in words:
        if len(word)<10:
            print(word)
            continue
        print(f'{word[0]}{len(word)-2}{word[-1]}')

main()
