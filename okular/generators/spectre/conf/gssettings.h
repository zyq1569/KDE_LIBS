// This file is generated by kconfig_compiler_kf5 from gssettings.kcfg.
// All changes you do to this file will be lost.
#ifndef GSSETTINGS_H
#define GSSETTINGS_H

#include <kconfigskeleton.h>
#include <QCoreApplication>
#include <QDebug>

class GSSettings : public KConfigSkeleton
{
  public:

    static GSSettings *self();
    ~GSSettings();

    /**
      Set Use Platform Fonts
    */
    static
    void setPlatformFonts( bool v )
    {
      if (!self()->isPlatformFontsImmutable())
        self()->mPlatformFonts = v;
    }

    /**
      Get Use Platform Fonts
    */
    static
    bool platformFonts()
    {
      return self()->mPlatformFonts;
    }

    /**
      Is Use Platform Fonts Immutable
    */
    static
    bool isPlatformFontsImmutable()
    {
      return self()->isImmutable( QStringLiteral( "PlatformFonts" ) );
    }

  protected:
    GSSettings();
    friend class GSSettingsHelper;


    // General
    bool mPlatformFonts;

  private:
};

#endif
