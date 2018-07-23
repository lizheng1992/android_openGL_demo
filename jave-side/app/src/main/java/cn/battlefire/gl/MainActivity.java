package cn.battlefire.gl;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;
class MyGLRenderer implements GLSurfaceView.Renderer {
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        Native.InitOpenGL();
    }
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        Native.OnViewportChanged(width,height);
    }
    public void onDrawFrame(GL10 gl) {
        Native.RenderOneFrame();
    }
}
class MyGLSurface extends GLSurfaceView {
    MyGLRenderer mRenderer;
    public MyGLSurface(Context context) {
        super(context);
        setEGLContextClientVersion(2);
        mRenderer=new MyGLRenderer();
        setRenderer(mRenderer);
    }
}
public class MainActivity extends AppCompatActivity {
    MyGLSurface mView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Native.InitAssetManager(getAssets());
        mView=new MyGLSurface(getApplication());
        setContentView(mView);
    }
}