
class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;

        Bucket(int c) : count(c) {}
    };

    list<Bucket> buckets;

    unordered_map<string, list<Bucket>::iterator> keyBucket;

public:
    AllOne() {}

    void inc(string key) {
        if (!keyBucket.count(key)) {
            if (buckets.empty() ||
                buckets.front().count != 1) {
                buckets.push_front(Bucket(1));
            }

            buckets.front().keys.insert(key);
            keyBucket[key] = buckets.begin();
            return;
        }

        auto it = keyBucket[key];
        auto nextIt = next(it);

        int newCount = it->count + 1;

        if (nextIt == buckets.end() ||
            nextIt->count != newCount) {
            nextIt = buckets.insert(nextIt, Bucket(newCount));
        }

        nextIt->keys.insert(key);
        keyBucket[key] = nextIt;

        it->keys.erase(key);

        if (it->keys.empty())
            buckets.erase(it);
    }

    void dec(string key) {
        if (!keyBucket.count(key)) return;

        auto it = keyBucket[key];

        int newCount = it->count - 1;

        if (newCount == 0) {
            keyBucket.erase(key);
        } else {
            auto prevIt = it;

            if (it == buckets.begin() ||
                prev(prevIt)->count != newCount) {
                prevIt = buckets.insert(it, Bucket(newCount));
            } else {
                prevIt = prev(it);
            }

            prevIt->keys.insert(key);
            keyBucket[key] = prevIt;
        }

        it->keys.erase(key);

        if (it->keys.empty())
            buckets.erase(it);
    }

    string getMaxKey() {
        if (buckets.empty()) return "";

        return *buckets.back().keys.begin();
    }

    string getMinKey() {
        if (buckets.empty()) return "";

        return *buckets.front().keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */