/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GNode.h
@Time: 2021/6/1 10:13 下午
@Desc: 
***************************/

#ifndef CGRAPH_GNODE_H
#define CGRAPH_GNODE_H

#include "../GElement.h"
#include "GNodeDefine.h"

CGRAPH_NAMESPACE_BEGIN

class GNode : public GElement {
protected:
    /**
     * 构造函数
     */
    explicit GNode();

    /**
     * 执行批量任务
     * @param tasks
     * @param ttl
     * @return
     */
    CStatus doParallel(const UTaskGroup& tasks, CMSec ttl);

    /**
     * 异步执行信息，适用于传入静态类函数或者lambda表达式信息
     * @tparam Func
     * @tparam Args
     * @param func
     * @param args
     */
    template<typename Func, typename... Args>
    static CStatus doDetach(const Func&& func, Args&&... args);

    /**
    * 获取当前执行的线程id信息
    * @return
    */
    static CSize getThreadId();

private:
    GNodeType node_type_;                    // 节点类型
};

using GNodePtr = GNode *;
using GNodePtrArr = std::vector<GNodePtr>;

CGRAPH_NAMESPACE_END

#include "GNode.inl"

#endif //CGRAPH_GNODE_H