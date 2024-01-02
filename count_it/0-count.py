#!/usr/bin/python3
"""Count it! task"""
import requests


def count_words(subreddit, word_list, after=None, count=None):
    """_summary_

    Args:
        subreddit (_type_): _description_
        word_list (_type_): _description_
        after (_type_, optional): _description_. Defaults to None.
        count (_type_, optional): _description_. Defaults to None.

    Returns:
        _type_: _description_
    """

    if count is None:
        count = {}
    if after is None:
        url = "https://www.reddit.com/r/{}/hot.json".format(
            subreddit)
    else:
        url = "https://www.reddit.com/r/{}/hot.json?after={}".format(
            subreddit, after)
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"}

    res = requests.get(url, headers=headers, allow_redirects=False)
    if res.status_code == 200:
        data = res.json()
        posts = data['data']['children']
        for post in posts:
            title = post['data']['title']
            words = title.lower().split()
            for word in word_list:
                if word.lower() in words:
                    count[word] = count.get(word, 0) + words.count(
                        word.lower())

        after = data['data']['after']
        if after is not None:
            return count_words(
                subreddit, word_list, after, count)
    else:
        pass

    sorted_counts = sorted(count.items(), key=lambda x: (-x[1], x[0]))
    for word, count in sorted_counts:
        print("{}: {}".format(word.lower(), count))
