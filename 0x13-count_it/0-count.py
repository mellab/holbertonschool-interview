#!/usr/bin/python3
""" Count it! """

import requests


BASE_URL = "https://www.reddit.com/"
HEADERS = {'user-agent': 'holbiapp/1.0.0'}


def count_words(subreddit, word_list, after="", word_dic={}):
    """
    returns a sorted count of a given kyword or set of keywords
    """
    if not word_dic:
        for word in word_list:
            word_dic[word] = 0

    if after is None:
        word_list = [[key, value] for key, value in word_dic.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for w in word_list:
            if w[1]:
                print("{}: {}".format(w[0].lower(), w[1]))
        return None

    url = BASE_URL + "r/{}/hot/.json".format(subreddit)

    params = {
        'limit': 100,
        'after': after
    }

    res = requests.get(url,
                       headers=HEADERS,
                       params=params,
                       allow_redirects=False)

    if res.status_code != 200:
        return None

    try:
        json_body = res.json()

    except ValueError:
        return None

    try:
        data = json_body.get("data")
        after = data.get("after")
        children = data.get("children")
        for child in children:
            post = child.get("data")
            title = post.get("title")
            lower = [s.lower() for s in title.split(' ')]

            for w in word_list:
                word_dic[w] += lower.count(w.lower())

    except Exception:
        return None

    count_words(subreddit, word_list, after, word_dic)
