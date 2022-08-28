#pragma once
#include "asio.hpp"
#include <set>

namespace wheat
{

template <typename T>
class VoteCounter
{
public:
    template <typename U>
    bool Agree(U&& u)
    {
        return m_who_agree.emplace(std::forward<U>(u)).second;
    }

    template <typename U>
    bool Refuse(U && u)
    {
        return m_who_refuse.emplace(std::forward<U>(u)).second;
    }

    std::pair<size_t, size_t> GetVotes() const
    {
        return std::make_pair(m_who_agree.size(), m_who_refuse.size());
    }

private:
    std::set<T> m_who_agree;
    std::set<T> m_who_refuse;
};


}