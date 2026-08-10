class Twitter {
private:
    int time;

    unordered_map<int, vector<pair<int, int>>> tweets;

    unordered_map<int, unordered_set<int>> following;

public:

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

       
        priority_queue<
            tuple<int, int, int>
        > pq;


        if (!tweets[userId].empty()) {
            int index = tweets[userId].size() - 1;

            pq.push({
                tweets[userId][index].first,
                userId,
                index
            });
        }

        // Tweets of followed users
        for (int followee : following[userId]) {

            if (!tweets[followee].empty()) {

                int index = tweets[followee].size() - 1;

                pq.push({
                    tweets[followee][index].first,
                    followee,
                    index
                });
            }
        }

        vector<int> ans;

        // Get 10 most recent tweets
        while (!pq.empty() && ans.size() < 10) {

            auto [timestamp, user, index] = pq.top();
            pq.pop();

            ans.push_back(tweets[user][index].second);

            // Move to the next older tweet of this user
            if (index > 0) {

                int nextIndex = index - 1;

                pq.push({
                    tweets[user][nextIndex].first,
                    user,
                    nextIndex
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
