if __name__ == '__main__':
    num_of_words = int(input())
    words = list(input().strip().split(' '))

    for i in range(1, num_of_words):
        words[i] = sorted(words[i])
        words[i] = set(words[i])
        words[i] = ''.join(words[i])

    # print(words)
    print(len(set(words)))
