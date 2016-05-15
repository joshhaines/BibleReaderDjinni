// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from br_base_view_model.djinni

package com.thoughtsofanintrovert.brDjinni;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class BrBaseViewModel {
    public abstract void setXml(String xml);

    public static native BrBaseViewModel create();

    private static final class CppProxy extends BrBaseViewModel
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public void setXml(String xml)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setXml(this.nativeRef, xml);
        }
        private native void native_setXml(long _nativeRef, String xml);
    }
}
