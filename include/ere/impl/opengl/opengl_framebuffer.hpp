#ifndef __ERE_OPENGL_FRAMEBUFFER_HPP__
#define __ERE_OPENGL_FRAMEBUFFER_HPP__

#include <ere/ere_config.hpp>

#ifdef USE_OPENGL

#include <ere/api/framebuffer_api.hpp>

namespace ere {

class opengl_framebuffer : public framebuffer_api {
public:

    opengl_framebuffer(int t_width, int t_height);

    virtual ~opengl_framebuffer() override;

    virtual void bind() const override;
    virtual void unbind() const override;

    virtual void disable_color_attachment() const override;

    virtual int get_id() const override;

    virtual int get_width() const override;
    virtual int get_height() const override;

    virtual bool is_valid() const override;

    virtual ref<texture_api> add_color_attachment() override;
    inline virtual ref<texture_api> get_color_attachemt() const override { return m_color_attachment; }
    virtual ref<texture_api> add_depth_attachment() override;
    inline virtual ref<texture_api> get_depth_attachemt() const override { return m_depth_attachment; }
    virtual ref<texture_api> add_stencil_attachment() override;
    inline virtual ref<texture_api> get_stencil_attachemt() const override { return m_stencil_attachment; }
    virtual ref<texture_api> add_depth_stencil_attachment() override;
    inline virtual ref<texture_api> get_depth_stencil_attachemt() const override { return m_depth_stencil_attachment; }
    virtual void add_depth_stencil_attachment_write_only() override;

    friend class opengl_renderer;

private:

    unsigned int m_id;
    int m_width;
    int m_height;

    ref<texture_api> m_color_attachment = nullptr;
    ref<texture_api> m_depth_attachment = nullptr;
    ref<texture_api> m_stencil_attachment = nullptr;
    ref<texture_api> m_depth_stencil_attachment = nullptr;

    unsigned int m_rbo_id = 0;
};

}

#endif // USE_OPENGL

#endif // __ERE_OPENGL_FRAMEBUFFER_HPP__