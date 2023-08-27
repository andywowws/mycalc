#include <calcbase.h>
int na[10001], nb[10001], nc[10001];
int compare(string a, string b) {
    int pos1 = a.find('.');
    int pos2 = b.find('.');
    bool neg = 0;
    if (pos1 != -1 && pos2 == -1) b += ".0";
    if (pos2 != -1 && pos1 == -1) a += ".0";
    if (pos2 != -1 || pos1 != -1) neg = 1;
    if (neg) {
        int com = compare(a.substr(0, a.find('.')), b.substr(0, b.find('.')));
        if (com == 1) return 1;
        if (com == 0) return 0;
        if (com == 2)
            return compare(a.substr(a.find('.') + 1, a.length() - a.find('.')),
                           b.substr(b.find('.') + 1, b.length() - b.find('.')));
    }
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return 2;
}
string myformat(string a, int b, int c) {
    if (c == 0) a.push_back('.');
    for (int i = 1; i <= b - c; i++) a.push_back('0');
    return a;
}
string calcbase::add(string a, string b, bool xs) {
    int w1 = 0, w2 = 0, wr, sr, la = a.length(), lb = b.length();
    bool k1 = 0, k2 = 0;
    int fa = a.find('.');
    int fb = b.find('.');
    if (a.find('-') != string::npos) {
        k1 = 1;
        a.erase(a.begin());
    }
    if (b.find('-') != string::npos) {
        k2 = 1;
        b.erase(b.begin());
    }
    if (!k2 && k1) return sub(b, a, 0);
    if (!k1 && k2) return sub(a, b, 0);
    if (fa != string::npos) w1 = a.length() - fa - 1;
    if (fb != string::npos) w2 = b.length() - fb - 1;
    if (w1 > 0 || w2 > 0) {
        a = myformat(a, max(w1, w2), w1);
        b = myformat(b, max(w1, w2), w2);
        return (add(a.substr(0, a.find('.')), b.substr(0, b.find('.')), 0) +
                "." +
                add(a.substr(a.find('.') + 1, a.length() - a.find('.')),
                    b.substr(b.find('.') + 1, b.length() - b.find('.')), 0));
    }
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++) na[i] = a[i] - '0';
    for (int i = 0; i < b.length(); i++) nb[i] = b[i] - '0';
    for (int i = 0; i < max(la, lb); i++) {
        nc[i] += (na[i] + nb[i]);
        nc[i + 1] = nc[i] / 10;
        nc[i] %= 10;
    }
    wr = max(la, lb);
    sr = max(w1, w2);
    if (nc[max(la, lb)] != 0)
        wr -= 0;
    else
        wr -= 1;
    string c;
    for (int i = 0; i <= wr; i++) c.push_back(nc[i] + '0');
    if (sr > 0) c.insert(sr, 1, '.');
    reverse(c.begin(), c.end());
    if (xs)
        for (int i = 1; i <= a.length() - c.length(); i++)
            c.insert(c.begin(), '0');
    if (k1 && k2) c.insert(c.begin(), '-');
    return c;
}
string calcbase::sub(string a, string b, bool xs) {
    if (compare(a, b) == 2) return "0";
    if (compare(a, b) == 0) return "-" + sub(b, a, 0);
    int w1 = 0, w2 = 0, wr, sr, la = a.length(), lb = b.length();
    bool k1 = 0, k2 = 0;
    if (*a.begin() == '-') {
        k1 = 1;
        a.erase(a.begin());
    }
    if (*b.begin() == '-') {
        k2 = 1;
        b.erase(b.begin());
    }
    if (k1 && k2) return sub(b, a, 0);
    if (k1) return "-" + add(a, b, 0);
    if (k2) return add(a, b, 0);
    int fa = a.find('.');
    int fb = b.find('.');
    if (fa != string::npos) w1 = a.length() - fa - 1;
    if (fb != string::npos) w2 = b.length() - fb - 1;
    if (w1 > 0 || w2 > 0) {
        a = myformat(a, max(w1, w2), w1);
        b = myformat(b, max(w1, w2), w2);
        return (sub(a.substr(0, a.find('.')), b.substr(0, b.find('.')), 0) +
                "." +
                sub(a.substr(a.find('.') + 1, a.length() - a.find('.')),
                    b.substr(b.find('.') + 1, b.length() - b.find('.')), 1));
    }
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++) na[i] = a[i] - '0';
    for (int i = 0; i < b.length(); i++) nb[i] = b[i] - '0';
    for (int i = 0; i < max(la, lb); i++) {
        if (na[i] < nb[i]) {
            na[i + 1]--;
            na[i] += 10;
        }
        nc[i] = na[i] - nb[i];
    }
    wr = max(la, lb);
    sr = max(w1, w2);
    while (nc[wr] == 0 && wr > 0) wr--;
    string c;
    for (int i = 0; i <= wr; i++) c.push_back(nc[i] + '0');
    reverse(c.begin(), c.end());
    if (xs)
        for (int i = 1; i <= a.length() - c.length(); i++)
            c.insert(c.begin(), '0');
    if (k1 && k2) c.insert(c.begin(), '-');
    return c;
}
string calcbase::mcl(string a, string b) {
    bool an = 0, bn = 0;
    if (*a.begin() == '-') {
        an = true;
        a.erase(0, 1);
    }
    if (*b.begin() == '-') {
        bn = true;
        b.erase(0, 1);
    }
    int w1 = 0, w2 = 0;
    int fa = a.find('.');
    int fb = b.find('.');
    if (fa != string::npos) {
        w1 = a.length() - fa - 1;
        a.erase(fa, 1);
    }
    if (fb != string::npos) {
        w2 = b.length() - fb - 1;
        b.erase(fb, 1);
    }
    int wr = w1 + w2;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));
    for (int i = 0; i < a.size(); i++) na[i] = a[i] - '0';
    for (int i = 0; i < b.size(); i++) nb[i] = b[i] - '0';
    for (int i = 0; i < a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.size(); j++) {
            nc[i + j] += na[i] * nb[j] + carry;
            carry = nc[i + j] / 10;
            nc[i + j] %= 10;
        }
        nc[i + b.length()] += carry;
    }
    int index = a.size() + b.size();
    while (nc[index] == 0 && index > 0) index--;
    string c;
    for (int i = 0; i <= index; i++) {
        c.push_back(nc[i] + '0');
    }
    reverse(c.begin(), c.end());
    int check = an + bn;
    if (wr > 0) c.insert(c.size() - wr, 1, '.');
    if (check == 1) c = '-' + c;
    return c;
}
