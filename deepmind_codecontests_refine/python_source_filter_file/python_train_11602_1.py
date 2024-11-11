import sys
import itertools

WILDCARD = '?'
FILL = 'x'


def main():
    pattern_count = int(sys.stdin.readline())
    patterns = itertools.islice(sys.stdin, pattern_count)
    result = intersect_patterns(p.strip() for p in patterns)
    print(result)


def intersect_patterns(lines):
    return ''.join(_intersect_patterns(lines))


def _intersect_patterns(lines):
    for column in zip(*lines):
        literals = set(column).difference(WILDCARD)
        if literals:
            literal, *remaining = literals.pop()
            yield WILDCARD if remaining else literal
        else:
            yield FILL

if __name__ == '__main__':
    main()