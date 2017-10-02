
#ifndef __borc_compilerimpl_hpp__
#define __borc_compilerimpl_hpp__

#include "Compiler.hpp"

#include <set>

namespace borc {

    /**
     * @brief Default compiler implementation
     */
    class CompilerImpl : public Compiler {
    public:
        explicit CompilerImpl(const FileTypeRegistry *registry, const std::string &toolName, const std::set<const FileType*> &types);

        explicit CompilerImpl(const FileTypeRegistry *registry, const std::string &toolName, const std::set<const FileType*> &types, const std::string &path);

        virtual ~CompilerImpl();

        virtual bool isCompilable(const Source *source) const override;

        virtual std::string getToolName() const override;

        virtual std::string getPath() const override;
        
        virtual std::unique_ptr<Task> createTask(const Source *source) override;

    private:
        std::string m_toolName;
        std::string m_path;
        const FileTypeRegistry *m_registry;

        std::set<const FileType*> m_supportedTypes;

        std::string m_switchSymbol;
    };
}

#endif 
